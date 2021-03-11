public interface ParticulaMasurabila {
    public double distantaPanaLa(Particula p);

    public static double distantaEuclidiana(Particula a, Particula b) {
        int xDelta = a.getX() - b.getX();
        int yDelta = a.getY() - b.getY();

        return Math.sqrt((double)(xDelta*xDelta + yDelta*yDelta));
    }


    public double distantaOrigine();
}
