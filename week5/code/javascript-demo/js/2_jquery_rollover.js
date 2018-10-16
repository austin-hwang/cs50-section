$(document).ready(function() {

    $("#frog").mouseover(function(){
        $(this).attr("src","img/frog2.png");
        $(".some_text").css("color","green");
        $("#update_text").text("mouseover");
    });							
    
    $("#frog").mouseout(function(){
        $(this).attr("src","img/frog1.png");
        $(".some_text").css("color","black");
        $("#update_text").text("mouseout");
    });							
    
    $("#frog").click(function(){
        $(this).attr("src","img/prince.jpg");
        $(".some_text").css("color","red");
        $("#update_text").text("click");
    });							
    
    /*
    TO TRY
    1. Change to a prince on doubleclick
    2. Change font size of text by chaining .css calls
    3. Update html vs. text
    */
							
    
});
