var inputId = document.getElementById('id5');

function clear() {
    inputId.value = "0";
}

function fhequal() {
    alert("占位");
}

function backspace() {
    var leng = inputId.value.length;
    if (leng < 2) {
        inputId.value = "0";
    } else {
        inputId.value = inputId.value.substr(0, leng - 1);
    }
}

function number0() {
    if (inputId.value === "0") {
        inputId.value = "0";
    } else {
        inputId.value = inputId.value + "0";
    }
}

function number1() {
    if (inputId.value === "0") {
        inputId.value = "1";
    } else {
        inputId.value = inputId.value + "1";
    }
}

function number2() {
    if (inputId.value === "0") {
        inputId.value = "2";
    } else {
        inputId.value = inputId.value + "2";
    }
}

function number3() {
    if (inputId.value === "0") {
        inputId.value = "3";
    } else {
        inputId.value = inputId.value + "3";
    }
}

function number4() {
    if (inputId.value === "0") {
        inputId.value = "4";
    } else {
        inputId.value = inputId.value + "4";
    }
}

function number5() {
    if (inputId.value === "0") {
        inputId.value = "5";
    } else {
        inputId.value = inputId.value + "5";
    }
}

function number6() {
    if (inputId.value === "0") {
        inputId.value = "6";
    } else {
        inputId.value = inputId.value + "6";
    }
}

function number7() {
    if (inputId.value === "0") {
        inputId.value = "7";
    } else {
        inputId.value = inputId.value + "7";
    }
}

function number8() {
    if (inputId.value === "0") {
        inputId.value = "8";
    } else {
        inputId.value = inputId.value + "8";
    }
}

function number9() {
    if (inputId.value === "0") {
        inputId.value = "9";
    } else {
        inputId.value = inputId.value + "9";
    }
}

function fhPI() {
    if (inputId.value == "0") {
        inputId.value = "π";
    } else {
        inputId.value = inputId.value + "π";
    }
}

function fhe() {
    if (inputId.value === "0") {
        inputId.value = "e";
    } else {
        inputId.value = inputId.value + "e";
    }
}

function fhtan() {
    if (inputId.value === "0") {
        inputId.value = "tan";
    } else {
        inputId.value = inputId.value + "tan";
    }
}

function fhsin() {
    if (inputId.value === "0") {
        inputId.value = "sin";
    } else {
        inputId.value = inputId.value + "sin";
    }
}

function fhcos() {
    if (inputId.value === "0") {
        inputId.value = "cos";
    } else {
        inputId.value = inputId.value + "cos";
    }
}

function fhsqrt() {
    if (inputId.value === "0") {
        inputId.value = "sqrt";
    } else {
        inputId.value = inputId.value + "sqrt";
    }
}

function fhmutiply() {
    inputId.value = inputId.value + "*";
}

function fhadd() {
    inputId.value = inputId.value + "+";
}

function fhsubtraction() {
    inputId.value = inputId.value + "-";
}

function fhdivide() {
    inputId.value = inputId.value + "/";
}

function fhmod() {
    inputId.value = inputId.value + "%";
}