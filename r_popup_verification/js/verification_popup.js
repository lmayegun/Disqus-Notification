(function($) {
  $(document).ready(function(){

    var verifier    = new RegExp(Drupal.settings.r_popup_js_var.verifyReg, "i");
    var currentPath = Drupal.settings.r_popup_js_var.currentPath;
    var basePath    = Drupal.settings.r_popup_js_var.basePath;
    var baseUrl     = Drupal.settings.r_popup_js_var.baseUrl;
    var nodeId      = Drupal.settings.r_popup_js_var.nodeId;

    $.colorbox({
      inline      : true,
      closeButton : false,
      width       : '90%',
      href        : '.advance-log-message',
      className   : 'advance-popup',
      overlayClose: false,
    });

    onForm_submit();
    localStorage_checker();

    function onForm_submit() {
      $("#verification_form").submit( function(evt){
         evt.preventDefault();
         var inp = new String(this.v_id.value);
         console.log(inp.length);
         
         if( verifier.test(this.v_id.value) && inp.length == 8 ){
            $("#colorbox").delay(1000).fadeOut();
            $("#cboxOverlay").delay(1000).fadeOut();
            sessionStorage.setItem('popState','shown');
            pageRedirect();
         }else{
            $("#vId").css({"border": "1px solid red"});
            $(".error-text").html("Please Enter A Valid Input");
         }
      });
    }

    function localStorage_checker(){
      if(sessionStorage.getItem('popState') != 'shown'){
          $("#verification_form").delay(2000).fadeIn();
          $("#node-"+nodeId).fadeOut();
      }else if(sessionStorage.getItem('popState') == 'shown'){
          $("#colorbox").hide();
          $("#cboxOverlay").hide();
      }
    }

    function pageRedirect() {
        window.location.replace(baseUrl+basePath+currentPath);
    }

  });
})(jQuery);

(function ($, Drupal, window, document, undefined) {
//Configure colorbox call back to resize with custom dimensions 
  $.colorbox.settings.onLoad = function() {
    colorboxResize();
  }
   
  //Customize colorbox dimensions
  var colorboxResize = function(resize) {
    var width = "90%";
    var height = "80%";
    
    /*if($(window).width() > 960) { width = "860" }
    if($(window).height() > 700) { height = "630" }*/
   
    $.colorbox.settings.height = height;
    $.colorbox.settings.width = width;
    
    //if window is resized while lightbox open
    if(resize) {
      $.colorbox.resize({
        'height': height,
        'width': width
      });
    } 
  }
  
  //In case of window being resized
  $(window).resize(function() {
    colorboxResize(true);
  });

})(jQuery, Drupal, this, this.document);