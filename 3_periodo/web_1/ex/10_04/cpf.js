function validateCPF(cpf) {
    //deixa só os números
    cpf = cpf.replace('.', '').replace('.', '').replace('-', '');

    //se não tiver 11 numeros ou for tudo igual é inválido
    if (cpf.length !== 11 || !!cpf.match(/(\d)\1{10}/)) return false;

    let sum = 0;
    for (let i = 0; i < 9; i++) {
        sum += parseInt(cpf[i]) * (10 - i);
    }
    let mod = (sum * 10) % 11;
    if (mod === 10 || mod === 11) mod = 0;
    
    if (mod !== parseInt(cpf[9])) return false;

    sum = 0;
    for (let i = 0; i < 10; i++) {
        sum += parseInt(cpf[i]) * (11 - i);
    }
    mod = (sum * 10) % 11;
    if (mod === 10 || mod === 11) mod = 0;

    if (mod !== parseInt(cpf[10])) return false;

    return true; 
}

//Teste
console.log(validateCPF("14789576740"));