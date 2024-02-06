function add() {
    var n1 = document.getelementbyid("N1");
    var n2 = document.getelementbyid("N2");
    document.getelementbyid("ans").innerHTML = n1+n2;
    return n1+n2;
}
function sub() {
    var n1 = document.getelementbyid("N1");
    var n2 = document.getelementbyid("N2");
    if (n1 < n2) {
        return n2-n1;
    }
    return n1-n2;
}
function mul() {
    var n1 = document.getelementbyid("N1");
    var n2 = document.getelementbyid("N2");
    return n1*n2;
}
function div() {
    var n1 = document.getelementbyid("N1");
    var n2 = document.getelementbyid("N2");
    if (n1 < n2) {
        return n2/n1;
    }
    return n1/n2;
}
