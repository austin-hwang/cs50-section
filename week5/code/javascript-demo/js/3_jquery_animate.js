$(document).ready(function(){

    $("#animate_button").click(function() {
        $("#animate_me").animate({height: 400},400)
            .animate({borderWidth: 10},300)
            .animate({width: 400},400)
            .animate({top: 100, left:100}, "slow")
            .animate({top: 0, left:200}, "slow");
    });
    
});
