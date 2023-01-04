package resolucoes;

public class Media {
    double Av1;
    double Av2;

    public void setAv1(double av1) {
        this.Av1 = av1;
    }

    public void setAv2(double av2) {
        this.Av2 = av2;
    }

    public double calcularMedia() {
        double media = (Av1+Av2)/2;

        return media;
    }
}
