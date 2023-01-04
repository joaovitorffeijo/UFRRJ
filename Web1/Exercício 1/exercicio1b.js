function data_hora() {
    var data = new Date();
    alert('Hoje é ' + data);
}

function data_hora_leg() {
    var data = new Date();
    document.write("Hoje é " + data);
}

// Não consegui utilizar document.getElementById("demo").innerHTML = data;