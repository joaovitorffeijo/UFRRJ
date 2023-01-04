package eleicoes;

public class Candidato {
    String nome;
    int numVotos;
    
    Candidato (String nome, int numVotos) {
        this.nome = nome;
        this.numVotos = numVotos;
    } // Construtor da classe.
}

/* Os objetos do tipo candidato possuem como variáveis "nome" (String) e "numVotos" (int). Dentro do método main
 * são alocados em um vetor e instanciados no "for" do método main utilizando o construtor "Candidato".
*/
