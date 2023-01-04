package problema2_pt1;

import java.awt.Rectangle;
public class MedidorDeArea implements Medidor {
public double medir(Object umObjeto) {
Rectangle umRetangulo = (Rectangle) umObjeto;
double area = umRetangulo.getWidth() * umRetangulo.getHeight();
return area;
}
}
