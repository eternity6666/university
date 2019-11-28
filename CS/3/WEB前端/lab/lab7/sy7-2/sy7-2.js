function change() {
    var curform = document.all.myform;
    curform.money.value = curform.country.options[curform.country.selectedIndex].value;
}

function sel() {
    var curform = document.all.myform;
    alert("该外汇的汇率是1 比 " + curform.money.value);
}