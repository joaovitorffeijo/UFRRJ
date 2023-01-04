package resolucoes;

public class TesteMedia {
    public static void main(String[] args) throws Exception {
        Media maria = new Media();
        Media marco = new Media();


        maria.setAv1(6.23);
        maria.setAv2(4.12);
        marco.setAv1(6.27);
        marco.setAv2(5.4);

        System.out.println("A media de maria e: " + maria.calcularMedia());
        System.out.println("A media de marco e: " + marco.calcularMedia());
    }
}
