package resolucoes;

public class TesteProduto {
    public static void main(String[] args) {
        Produto bola = new Produto("Bola de Futebol");

        System.out.println(bola.getNome());
        bola.setNome("Bola de Basquete");
        System.out.println(bola.getNome());
    }
}
