function isYear(year) {
    return year % 4 == 0 ? year % 100 != 0 : false;
}

function getDaysOfMonth(year, month) {
    if (month == 2) {
        return isYear(year) ? 29 : 28;
    } else if (month <= 7)
        return month % 2 == 0 ? 30 : 31;
    else
        return month % 2 != 0 ? 30 : 31;
}

function drawWeek() {
    var container = document.getElementById("div");
    container.innerHTML = "";
    var weeks = ["日", "一", "二", "三", "四", "五", "六"];
    for (var i in weeks) {
        var elem = document.createElement("div");
        elem.className = "block";
        elem.innerHTML = weeks[i];
        container.appendChild(elem);
    }
}

function drawSpace(a, b) {
    var container = document.getElementById("div");
    for (var i = a; i < b; i++) {
        var elem = document.createElement("div");
        elem.className = "block";
        elem.innerHTML = "&nbsp;";
        container.appendChild(elem);
    }
}

function draw(year, month, day, week) {
    var container = document.getElementById("div");
    drawWeek();
    var tmp = day % 7;
    var tmp1 = (week - tmp + 7 + 1) % 7;
    drawSpace(0, tmp1);
    var days = getDaysOfMonth(year, month);
    for (var i = 1; i <= days; i++) {
        var elem = document.createElement("div");
        elem.innerHTML = String(i);
        if (i == day) {
            elem.className = "block today";
        } else {
            elem.className = "block";
        }
        container.appendChild(elem);
    }
    if ((week + days - day) % 7 != 6)
        drawSpace((week + days - day) % 7, 6);
}
var date = new Date();
var year = date.getFullYear();
var month = date.getMonth();
var week = date.getDay();
var day = date.getDate();
draw(year, month + 1, day, week);