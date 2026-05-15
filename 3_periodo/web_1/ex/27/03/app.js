let button = document.getElementById('botao');
let button2 = document.getElementById('botao2');
let minhaDiv = document.getElementById('div').mouseover


button.onclick = function(){

    alert("nossos nomes: nathan, malu, ket");
    
}
function saudacao(nome){

    
    alert(nome);
    
}
function reagir(){
    minhaDiv.style.backgroundColor = 'yellow';
    minhaDiv.textContent = 'O mouse passou na imagem!';
}