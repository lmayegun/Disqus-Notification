(function($) {

//document.cookie = "username=John Doe";
function setcookie(cookieName,cookieValue) {
  var today = new Date();
  var expire = new Date();
  // 14 days 3600000*24*14
  expire.setTime(today.getTime() +  5000 );
  document.cookie = cookieName+"="+escape(cookieValue) + ";expires="+expire.toGMTString();
}
/**
 * get cookie by name without using a regular expression
 */
var getCookie = function(name) {
  var getCookieValues = function(cookie) {
    var cookieArray = cookie.split('=');
    return cookieArray[1].trim();
  };

  var getCookieNames = function(cookie) {
    var cookieArray = cookie.split('=');
    return cookieArray[0].trim();
  };

  var cookies = document.cookie.split(';');
  var cookieValue = cookies.map(getCookieValues)[cookies.map(getCookieNames).indexOf(name)];

  return (cookieValue === undefined) ? null : cookieValue;
};

/**
 * alternative: get cookie by name with using a regular expression
 */
var getCookiebyName = function(name){
  var pair = document.cookie.match(new RegExp(name + '=([^;]+)'));
  return !!pair ? pair[1] : null;
};

/**
 * [Gets the cookie value if the cookie key exists in the right format]
 * @param  {[string]} name [name of the cookie]
 * @return {[string]}      [value of the cookie]
 */
var getCookie = function (name) {
    return parseCookies()[name] || '';
};

/**
 * [Parsing the cookieString and returning an object of the available cookies]
 * @return {[object]} [map of the available objects]
 */
var parseCookies = function () {
  var cookieData = (typeof document.cookie === 'string' ? document.cookie : '').trim();

  return (cookieData ? cookieData.split(';') : []).reduce(function (cookies, cookieString) {
    var cookiePair = cookieString.split('=');

    cookies[cookiePair[0].trim()] = cookiePair.length > 1 ? cookiePair[1].trim() : '';

    return cookies;
  }, {});
};

//console.log(Drupal.settings.r_popup_js_var.cookie_timer);
//var cookie_key = window.Drupal.settings.r_popup_js_var.cookie_key;
//var jobsBoardPopupCookie = getCookie('jobs-board-seen-1'); 
//setcookie("username", "John Doe");
  $(document).bind('cbox_closed', function(){
    function setcookie(cookieName,cookieValue) {
      var today   = new Date();
      var expire  = new Date();

      // 14 days 3600000*24*14
      var cookie_timer = parseInt( Drupal.settings.r_popup_js_var.cookie_timer ); 
      expire.setTime( today.getTime() +  cookie_timer );
      console.log(cookie_timer);
      document.cookie = cookieName+"="+escape(cookieValue) + ";expires="+expire.toGMTString();
    }
    var cookie_key = Drupal.settings.r_popup_js_var.cookie_key;
    var jobsBoardPopupCookie = getCookie(cookie_key); 
    if( jobsBoardPopupCookie != 'yes'){
      setcookie(cookie_key,'yes'); 
    }
    $('.cookie-page-popup').remove();
  });

$(document).bind('cbox_open', function(){
  $("a.popupJobLink, .popupJobLink").click(function(event) {
   /* event.preventDefault(); 
    console.log(event);
    var targetHref = event.currentTarget.href; 
    window.open(targetHref); */
    $.colorbox.close();
  });
});

  $(document).ready(function(){
    var cookie_key = Drupal.settings.r_popup_js_var.cookie_key;
    var jobsBoardPopupCookie = getCookie(cookie_key); 
    var verifier    = new RegExp(Drupal.settings.r_popup_js_var.verifyReg, "i");
    var currentPath = Drupal.settings.r_popup_js_var.currentPath;
    var basePath    = Drupal.settings.r_popup_js_var.basePath;
    var baseUrl     = Drupal.settings.r_popup_js_var.baseUrl;
    var nodeId      = Drupal.settings.r_popup_js_var.nodeId;

    var year        = Drupal.settings.r_popup_js_var.year;
    var month       = Drupal.settings.r_popup_js_var.month; 
    var day         = Drupal.settings.r_popup_js_var.date; 
    var hour        = Drupal.settings.r_popup_js_var.hour; 
    var minute      = Drupal.settings.r_popup_js_var.minutes; 

    var date1       = new Date(year, month, day, hour, minute);
    var date2       = new Date();

    if( date1.getTime() >= date2.getTime() && jobsBoardPopupCookie != 'yes'){
      $(".cookie-page-popup").css("display","block");
      console.log( "Set date is greater than current time" );
      setTimeout(
        function(){ 
          $.colorbox({
          inline      : true,
          closeButton : true,
          fixed       : true,
          href        : '.cookie-page-popup',
          className   : 'cookie-page-popup',
          overlayClose: true,
        })},
        2000);
    }else{
       console.log("Set date is less than current time");
    }

    //Configure colorbox call back to resize with custom dimensions 
  $.colorbox.settings.onLoad = function() {
    colorboxResize();
  }
   
  //Customize colorbox dimensions
  var colorboxResize = function(resize) {
    var width = "40%";
    var height = "505px";
        
    //if window is resized while lightbox open
    if(resize && $(window).width() < 760 ) {
      /*$.colorbox.resize({
        //'height': height,
        'innerWidth': '100%',
        'width': '100%'
      });*/
    } 

    if(resize && $(window).width() > 760  && $(window).width() < 1200 ) {
      /*$.colorbox.resize({
        //'height': height,
        'innerWidth': '80%',
        'width': '100%'
      });*/
    } 

    if(resize && $(window).width() > 1200) {
      /*$.colorbox.resize({
        //'height': height,
        'width': '40%'
      });*/
    } 
  }
  
  //In case of window being resized
  $(window).resize(function() {
    colorboxResize(true);
  });



  });
})(jQuery);



(function ($, Drupal, window, document, undefined) {


})(jQuery, Drupal, this, this.document);