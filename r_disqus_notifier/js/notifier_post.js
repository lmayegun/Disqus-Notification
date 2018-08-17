(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.mybehavior = {
    attach: function (context, settings) {

    $('.alert .close').click(function(event) {
        event.preventDefault();
        alert("100");
    });

    }
  };

 $(window).resize(function() {
  // alert("raise");
  });
})(jQuery, Drupal, this, this.document);