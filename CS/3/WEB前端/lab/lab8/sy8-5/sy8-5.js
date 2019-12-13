function control() {
    var select = document.getElementById("select");
    var index = select.selectedIndex;
    if (index == -1) index = 0;
    var table1 = document.getElementById("table1");
    var table1Select = table1.children;
    for (i in table1Select) {
        if (i == index) table1Select[i].className = "";
        elsetable1Select[i].className = "hidden";
    }
    var table2 = document.getElementById("table2");
    var table2Select = table2.children;
    for (i in table2Select) {
        if (i == index) table2Select[i].className = "";
        elsetable2Select[i].className = "hidden";
    }
}

function put(a, b) {
    var select = document.getElementById("select");
    var index = select.selectedIndex;
    if (index == -1) index = 0;
    var table1 = document.getElementById("table" + String(a));
    var table1Select = table1.children;
    if (table1Select[index].length == 0) {
        alert("列表为空");
        return false;
    }
    var table1Index = table1Select[index].selectedIndex;
    if (table1Index == -1) {
        table1Index = 0;
    }
    var table1Option = table1Select[index].children;
    var table2 = document.getElementById("table" + String(b));
    var table2Select = table2.children;
    table2Select[index].appendChild(table1Option[table1Index]);
}

function putAll(a, b) {
    var select = document.getElementById("select");
    var index = select.selectedIndex;
    if (index == -1) index = 0;
    var table1 = document.getElementById("table" + String(a));
    var table1Select = table1.children;
    var table1Option = table1Select[index].children;
    var table2 = document.getElementById("table" + String(b));
    var table2Select = table2.children;
    var len = table1Option.length;
    for (var x = len - 1; x >= 0; x--) table2Select[index].appendChild(table1Option[x]);
}