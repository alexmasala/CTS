import java.util.Objects;

public class Particula extends Object {
    protected int x;
    protected int y;
    public final int xInitial = 0;
    public final int yInitial = 0;

    public Particula() {
        this.x = xInitial;
        this.y = yInitial;
    }

    public Particula(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    @Override
    public String toString() {
        return "Particula{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Particula)) return false;

        Particula particula = (Particula) o;

        if (x != particula.x) return false;
        return y == particula.y;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }
}
