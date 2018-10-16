$(document).ready(function(){

    $("#hide_button").click(function() {
        $(".test").hide();
    });

    $("#show_button").click(function() {
        $(".test").show();
    });

    $("#toggle_button").click(function() {
        $(".test").toggle();
    });

    /*
    TO TRY
    1. Make it affect the <p>'s rather than the .test's
    2. Control the duration of the show / hide / toggle
    3. Use fadeIn, fadeOut
    */
    
});
