package javacafe.Modules;

public class User {
    private final String name;
    private final String password;

    // Construtor para inicializar os campos
    public User(String name, String password) {
        this.name = name;
        this.password = password;
    }

    // Métodos getters para acessar os campos
    public String getName() {
        return name;
    }

    public String getPassword() {
        return password;
    }
}