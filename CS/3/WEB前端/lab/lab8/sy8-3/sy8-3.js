function selectNumber(n) {
    //彩票选号助手
    var number = new Array();
    var objsel = document.getElementById("number1");
    varselnum = objsel.options.length; //保存选项添加前总数
    for (j = 0; j <= n - 1; j++) {
        var list = "";
        //随机产生7 个 01~30 之间的整数
        for (i = 0; i <= 6; i++) {
            number[i] = Math.floor(Math.random() * 30 + 1); //下舍入if (number[i]<10)
            {
                number[i] = "0" + number[i];
            }
        }
        list = number.join(" ");
        //写入到列表框中
        var opt = document.createElement("option"); //创建一个列表项option
        var opt_text = document.createTextNode(list); //创建一个文本节点
        opt.value = j;
        opt.appendChild(opt_text); //将新的列表项节点加入DOM树
        objsel.appendChild(opt); //将新文本节点加入DOM树
    } // 始终将新添加的第一个列表项作为预选项
}

function delSelect() {
    var objSelect = document.getElementById("number1");
    var strIndex = objSelect.selectedIndex;
    if (strIndex != -1) {
        objSelect.options.remove(strIndex);
        console.log(strIndex);
    } else {
        alert("请先选择列表项后再删除！");
    }
}

function delSelectAll() {
    var objSelect = document.getElementById("number1");
    var strIndex = objSelect.options.length;
    if (strIndex > 0) {
        for (i = 0; i <= strIndex - 1; i++) {
            objSelect.options.remove(0);
        }
    } else {
        alert("请先选择列表项后再删除！");
    }
}