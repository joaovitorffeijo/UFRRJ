package eleicoes;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class VotacaoTeste {
    final static int MaxCandidatos = 7;
    public static void main(String[] args) throws IOException {
        Scanner entrada = new Scanner(new FileReader("votos.txt")); /* Instanciamento de um scanner para ler o 
                                                                                 arquivo com os votos. */
        PrintWriter saida = new PrintWriter(new FileWriter("resultados.txt")); /* Instanciamento de um 
                                                                                            "escrevedor" para escrever 
                                                                                            os resultados. */
        Candidato[] candidato = new Candidato[MaxCandidatos+1]; // Definição do vetor de objetos.

        for (int c = 1; c <= MaxCandidatos; c++)
            candidato[c] = new Candidato(entrada.nextLine(), 0); // Instanciamento dos objetos.

        ContagemVotos contagem = processarVotos(candidato, MaxCandidatos, entrada, saida);
        imprimirResultados(saida, candidato, MaxCandidatos, contagem);
        entrada.close();
        saida.close();
    }

    public static ContagemVotos processarVotos(Candidato[] lista, int max, Scanner entrada, PrintWriter saida) {
        ContagemVotos votos = new ContagemVotos(0, 0); // "voto" é o número do candidato.
        int voto = entrada.nextInt(); // Leitura do arquivo "votos.txt".
        while (voto != 0) {
            if (voto < 1 || voto > max) {
                saida.printf("Voto invalido: %d\n", voto);
                ++votos.invalidos;
            }
            else {
                ++lista[voto].numVotos;
                ++votos.validos;
            } /* Se o numero votado for valido, a quantidade de votos do candidato é acrescida de 1 e o numero de votos 
            validos tambem. */
            voto = entrada.nextInt();
        }
        return votos;
    }

    public static void imprimirResultados(PrintWriter out, Candidato[] lista, int max, ContagemVotos votos) {
        out.printf("\nNumero de votantes: %d\n", votos.validos + votos.invalidos);
        out.printf("Numero de votos validos: %d\n", votos.validos);
        out.printf("Numero de votos invalidos: %d\n", votos.invalidos);
        out.printf("\nCandidato Num de votos\n\n");

        for (int h = 1; h <= MaxCandidatos; h++)
            out.printf("%-18s %3d\n", lista[h].nome, lista[h].numVotos);

        out.printf("\nCandidato(s) eleitos(s)\n");
        int ganhador = encontrarMaisVotado(lista, 1, MaxCandidatos);
        int votosNoGanhador = lista[ganhador].numVotos;
        for (int candidato = 1; candidato <= MaxCandidatos; candidato++)
            if (lista[candidato].numVotos == votosNoGanhador) 
                out.printf(" %s\n", lista[candidato].nome);
                
        out.printf("\nCandidato(s) menos votado(s)\n");
        int piorDeTodos = encontrarMenosVotado(lista, 1, MaxCandidatos);
        int votosNoPior = lista[piorDeTodos].numVotos;
        for (int candidato = 1; candidato <= MaxCandidatos; candidato++)
            if (lista[candidato].numVotos == votosNoPior)
                out.printf(" %s\n", lista[candidato].nome); // Vai imprimir todos os candidatos com a mesma quantidade de votos do pior.
    }

    public static int encontrarMaisVotado(Candidato[] lista, int pri, int ult) {
        int maisVotado = pri;
        for (int candidato = pri + 1; candidato <= ult; candidato++)
            if (lista[candidato].numVotos > lista[maisVotado].numVotos) /* Nesse momento, caso exista mais de um 
                                                                           candidato com a mesma quantidade de votos, 
                                                                           só o primeiro a passar pelo if se tornará o 
                                                                           mais votado. */
                maisVotado = candidato;
        return maisVotado;
    }

    public static int encontrarMenosVotado(Candidato[] lista, int pri, int ult) {
        int menosVotado = pri;
        for (int candidato = pri + 1; candidato <= ult; candidato++)
            if (lista[candidato].numVotos < lista[menosVotado].numVotos)
                menosVotado = candidato; 
        return menosVotado;
    }

}