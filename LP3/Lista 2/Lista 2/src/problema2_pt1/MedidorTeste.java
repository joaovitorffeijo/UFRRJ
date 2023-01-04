package problema2_pt1;

import java.awt.Rectangle;

public class MedidorTeste {
    public static void main(String[] args) {
        Medidor medidorArea = new MedidorDeArea();
        
        Rectangle[] retangulos = new Rectangle[] {
            new Rectangle(5, 10, 20, 30),
            new Rectangle(10, 20, 30, 40),
            new Rectangle(20, 30, 5, 15)
        };

        double areaMedia = Entidade.calcularMedia(retangulos, medidorArea);
        System.out.printf("Média das áreas = %.2f", areaMedia);
}
}