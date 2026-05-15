console.log("hello, world");

var _global = 0; //nao recomendado
let _escopo = 0; //util 
const _imutavel = 0; //quando nao quiser alterar

//let para variavel de escopo
let x = 5;
let y = 10;

function soma(x , y){ //criando funcao
    return x + y;
}

let result = soma(x, y); //usando funcao

console.log(`A soma é ${result}`); //formatacao é com crase

//criando um objeto
const carro = {
    marca : "BMW", //propiedades do objeto
    modelo : "xi6",
    ligar : function (){ //metodo do objeto, faz algo relacionado ao objt
        console.log("O carro esta ligado");
    }
};

carro.ligar(); //usar o metodo do objeto

carro.buzinar = function (){ //adicionando um metodo ao objto ja existente
    console.log("bi bi");
};
carro.buzinar();

//arrays :)

let list = []; //arrays vazio
console.log(list);

//adicionar
list.push(0); //adicionando ao final do array um valor
console.log(list);

list.unshift(7,2,3,6); //adiciona no inicio
console.log(list);

//remover
list.pop(); //retira o ultimo item do array
console.log(list);

list.splice(1,1); //retira o elemento por indice
console.log(list);

let newList= list.filter(n => n !== 3); //cria uma nova lista sem o elemento
console.log(newList);
console.log(list);

//operacoes
list.sort(); //ordena a lista

list.length();//retorna o tamanho da lista


