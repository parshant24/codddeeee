let mainstr="";
function append(ab){
    if(ab=='='){
        mainstr=evaluate(mainstr);
    }else if(ab=='ac'){
        mainstr="";
    }else if(ab=="back"){
        mainstr=mainstr.slice(0,-1);
    }else{
        mainstr+=ab;
    }
    document.getElementById('displaybox').value=mainstr;
    alert(k);
    function draw() {
  ctx.clearRect(10, 10, WIDTH, HEIGHT);
  for (let i = 0; i < 100; i++) {
    ctx.beginPath();
    ctx.fillStyle = "rgb(255 0 0 / 50%)";
    ctx.arc(random(WIDTH), random(HEIGHT), random(50), 0, 2 * Math.PI);
    ctx.fill();
  }
}
draw();
}


//calcutor fxn used claude
function evaluate(str) {
  return eval(str.replace(/\^/g, "**")); // ^ becomes JS exponent **
}
k=6;
var k;
