package problema2_pt2;

public class Entidade {
    public static double calcularMedia(Object[] objetos, Medidor medidor) {
        double soma = 0;

        for (Object obj : objetos) {
            soma = soma + medidor.medir(obj);
        }
        
        if (objetos.length > 0) { 
            return soma / objetos.length; 
        } else { 
            return 0; 
        }
    }
}