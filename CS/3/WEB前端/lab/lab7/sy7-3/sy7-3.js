var input, div;

function mover() {
    div = document.getElementById('div');    
    div.style="background-color:#99cc66";
}

function mout() {
    div = document.getElementById('div');    
    div.style="background-color:#ff33ff";
}

function mmove() {
    div = document.getElementById('div');    
    div.style="background-color:#0033ff;";
}

function mdown() {
    input = document.getElementById('input');
    input.value = "按下鼠标";
}

function mclick() {
    input = document.getElementById('input');
    input.value = "单击鼠标"
}

function mdclick() {
    input = document.getElementById('input');
    input.value = "双击鼠标";
}