package problema2_pt2;

public class MedidorDeDisciplinas implements Medidor {
    
    public double medir(Object umObjeto) {
        double num_disc = MatricularAluno.alunos.get(umObjeto).size();;
        return num_disc;
    }
}
