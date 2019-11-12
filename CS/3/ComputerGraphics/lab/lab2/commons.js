var height;
var fs;

function move(a, b) {
    ctx.moveTo(fs * a, height - fs * b);
}

function line(a, b) {
    ctx.lineTo(fs * a, height - fs * b);
}

function bezierCurve(a, b, c, d, e, f) {
    ctx.bezierCurveTo(fs * a, height - fs * b, fs * c, height - fs * d, fs * e, height - fs * f);
}