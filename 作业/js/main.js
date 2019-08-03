window.onload = function(){
    var function1 = document.getElementById("function1");
    function1.onclick = function(){
        window.location.href="./function1.html";
    }

    var function2 = document.getElementById("function2");
    function2.onclick = function(){
        window.location.href="./function2.html";
    }

    var function3 = document.getElementById("function3");
    function3.onclick = function(){
        window.location.href="./function3.html";
    }

    var function4 = document.getElementById("function4");
    function4.onclick = function(){
        window.location.href="./function4.html";
    }
    
    // for(var i = 1; i <= 4;) {
    //     var string1 = "function" + i;
    //     var function1 = document.getElementById(string1);
    //     function1.onclick = function() {
    //         window.location.href = "./" + string1 + ".html";
    //     }
    // }
}
