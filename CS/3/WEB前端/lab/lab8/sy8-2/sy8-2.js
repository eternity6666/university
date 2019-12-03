function selectnumber(num) {
    //彩票选号助手
    var number = new Array();
    for (i = 0; i <= 6; i++) {
        number[i] = Math.floor(Math.random() * 30 + 1); //下舍入
    }
    document.getElementById(num).value = number.join(" ");
    //将数组元素数连接为字符串，中间用空格连接，作为 1 注彩票号码，写入文本框
}

function clear() {
    for(var i = 0; i < 3; i++){
        document.getElementById(String(i)).value = "";
    }
}