$(document).ready(function(){

    $("#1col_button").click(function() {
        $(".product").removeClass("col-xs-4");
        $(".product").addClass("col-xs-12");
    });

    $("#3col_button").click(function() {
        $(".product").removeClass("col-xs-12");
        $(".product").addClass("col-xs-4");
    });
});
