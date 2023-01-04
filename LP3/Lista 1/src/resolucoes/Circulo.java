package resolucoes;

public class Circulo {
    double raio;

    Circulo (double novoRaio) {
        raio = novoRaio;
    }

    double calcularArea () {
        return raio * raio * Math.PI;
    }

    double calcularPerimetro(){
        return 2 * Math.PI * raio;
    }
}