public class ParticulaAtomica extends Particula implements ParticulaMobila, ParticulaMasurabila {
    private String denumire;

    public ParticulaAtomica() {
        super();
    }

    public ParticulaAtomica(int x, int y, String denumire) {
        super(x, y);
        this.denumire = denumire;
    }

    public String getDenumire() {
        return denumire;
    }

    public void setDenumire(String denumire) {
        this.denumire = denumire;
    }

    @Override
    public String toString() {
        return "ParticulaAtomica{" +
                "x=" + x +
                ", y=" + y +
                ", denumire='" + denumire + '\'' +
                '}';
//        return "ParticulaAtomica{" + "denumire='" + denumire + '\'' + '}' + super.toString();
    }

    @Override
    public double distantaPanaLa(Particula p) {
        int xDelta = this.x - p.getX();
        int yDelta = this.y - p.getY();

        return Math.sqrt((double)(xDelta*xDelta + yDelta*yDelta));
    }

    @Override
    public double distantaOrigine() {
        int xDelta = this.x - super.xInitial;
        int yDelta = this.y - super.yInitial;

        return Math.sqrt((double)(xDelta*xDelta + yDelta*yDelta));
    }

    @Override
    public void mutaParticula(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public void incrementeazaCoordonate(int pas) {
        this.x += pas;
        this.y += pas;
    }

    @Override
    public void spuneParticula(String s) {
        System.out.println(s + " " + s);
    }
}
