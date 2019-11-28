function getFocus() {
    var body = document.getElementById('body');
    body.className = 'backgroundBlue';
}

function loseFocus() {
    var body = document.getElementById('body');
    body.className = 'backgroundWhite';
}

function submitTest() {
    var msg = "表单数据的获取：\n";
    msg += "昵称: ";
    var username = document.getElementById("input1").value;
    msg += username;
    msg += "\n密码: ";
    var psw = document.getElementById("input2").value;
    msg += psw;
    alert(msg);
    return false;
}

function resetTest() {
    alert("将数据清空");
}
