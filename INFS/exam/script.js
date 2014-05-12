var allDivs = document.getElementsByTagName('div');
var i, j;
for (i in allDivs) {
    allDivs[i].onclick = function() {
        sameColoredDivs = document.getElementsByClassName(this.className);
        for (j in sameColoredDivs) {
            sameColoredDivs[j].classList.add('active');
        }
    };
}