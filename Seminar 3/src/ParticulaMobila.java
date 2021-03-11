public interface ParticulaMobila {
    public void mutaParticula(int x, int y);

    public void incrementeazaCoordonate(int pas);

    // TO DO
    // sa se defineasca si sa implementeze o metoda default in interfata
    // si care ulterior sa fie suprascrisa in clasa ce implementeza interfata

    public default void spuneParticula(String s) {
        System.out.println(s);
    }
}
