package problema2_pt2;

public class MedidorTeste {
    public static void main(String[] args) {
        Medidor medidorDisc = new MedidorDeDisciplinas();
        MatricularAluno.matricula();

        double media = Entidade.calcularMedia(MatricularAluno.alunos.keySet().toArray(), medidorDisc);
        System.out.printf("\nMedia de disciplinas por aluno: %.4f", media);
    }
}
