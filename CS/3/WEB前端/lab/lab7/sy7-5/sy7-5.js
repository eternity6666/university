var pageOpen = new Date();

function stay() {
    var pageClose = new Date();
    var minutes = (pageClose.getMinutes() - pageOpen.getMinutes());
    var seconds = (pageClose.getSeconds() - pageOpen.getSeconds());
    var time = (seconds + (minutes * 60));
    time = (time + " 秒钟");
    alert(' 您在这儿停留了' + time + '. 欢迎下次再来!');
}