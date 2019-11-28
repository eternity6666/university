function confirmUser() {
    var name = document.getElementById("user").value;
    var len = name.length;
    if (len == 0)
        alert("用户名不能为空！");
    else if (len < 6)
        alert("用户名过短！");
    else if (len > 20)
        alert("用户名过长！");
    else {
        if (0 <= name.charAt(0) && name.charAt(0) <= '9') {
            alert("用户名不能以数字开头！")
        } else
            return true;
    }
    return false;
}

function confirmPwd() {
    var pwd = document.getElementById("pwd").value;
    var len = pwd.length;
    if (len == 0)
        alert("请注意密码不能为空！");
    else if (len < 6)
        alert('密码过短！');
    else if (len > 10)
        alert('密码过长！');
    else
        return true;
    return false;
}

function confirmRePwd() {
    if (confirmPwd()) {
        var pwd = document.getElementById("pwd").value;
        var rePwd = document.getElementById("rePwd").value;
        if (pwd != rePwd)
            alert("两次填写的密码不同");
        else
            return true;
    }
    return false;
}

function confirmEmail() {
    var email = document.getElementById("email").value;
    var patt = /[0-9a-z]+@[0-9a-z]+.[0-9a-z]+/i;
    if (patt.test(email))
        return true;
    else
        alert("邮箱不合法")
    return false;
}

function submit() {
    return confirmUser() && confirmRePwd() && confirmEmail() && false;
}