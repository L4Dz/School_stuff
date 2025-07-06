🧬 Herança de Classes em C++
📘 Descrição Geral
A herança em C++ é um mecanismo da programação orientada a objetos que permite criar uma classe derivada (filha) baseada em uma classe base (pai). Isso possibilita o reuso de código, especialização de comportamentos e uma estrutura mais modular e escalável.

Sintaxe básica:
cpp
Copiar
Editar
class Base {
public:
void show() {
std::cout << "Base class\n";
}
};

class Derived : public Base {
// Inherits all public and protected members of Base
};
🧩 Tipos de Herança
Tipo	Sintaxe	Acesso aos membros da base
Pública	class Derived : public Base	Mantém public e protected como estão
Protegida	class Derived : protected Base	public e protected viram protected
Privada	class Derived : private Base	public e protected viram private

⚠️ Pontos de Atenção
✅ Manter Interface Consistente
Métodos herdados devem manter a mesma assinatura.

Ao sobrescrever métodos, use sempre a palavra-chave override (desde o C++11) para evitar erros sutis:

cpp
Copiar
Editar
class Base {
public:
virtual void print() const;
};

class Derived : public Base {
public:
void print() const override; // Correto
};
⚙️ const e Qualificadores
Se um método na classe base é const, ele deve ser const também na classe derivada.

Idem para virtual, override, final.

cpp
Copiar
Editar
class Base {
public:
virtual void display() const;
};
🔄 Construtores e Inicialização
A classe derivada deve chamar o construtor da base se este tiver parâmetros:

cpp
Copiar
Editar
class Base {
public:
Base(int x) { ... }
};

class Derived : public Base {
public:
Derived(int x, int y) : Base(x) { ... }
};
🧼 Destrutores virtuais
Classes com herança devem ter destrutores virtual para evitar memory leaks em deleções via ponteiros base.

cpp
Copiar
Editar
class Base {
public:
virtual ~Base(); // Obrigatório em herança polimórfica
};
🧠 Classes Abstratas e Métodos Virtuais Puros
Uma classe com pelo menos um método virtual puro é abstrata:

cpp
Copiar
Editar
class Shape {
public:
virtual void draw() const = 0; // método puro
};
Essas classes não podem ser instanciadas diretamente, apenas por meio de classes derivadas que implementem os métodos puros.

🔁 Estendendo Funcionalidade
Sobrescrevendo métodos (override):

cpp
Copiar
Editar
class Derived : public Base {
void print() const override;
};
Chamando o método da base:

cpp
Copiar
Editar
void Derived::print() const {
Base::print(); // opcional
std::cout << "Extra logic\n";
}
Adicionando novos membros:

cpp
Copiar
Editar
class Derived : public Base {
void newMethod();
};
🔒 Acesso a Membros
private: não acessível pela classe filha

protected: acessível apenas por classes derivadas

public: acessível por todos

🧪 Upcasting e Downcasting
Upcasting é automático:

cpp
Copiar
Editar
Derived d;
Base* ptr = &d; // ok
Downcasting exige dynamic_cast e deve ser usado com cuidado.

✅ Boas Práticas
Use override sempre que sobrescrever métodos virtuais.

Prefira composição a herança quando possível.

Evite heranças múltiplas se não dominar bem o tema.

Sempre torne o destrutor virtual se a classe tiver métodos virtuais.

Documente bem a interface da classe base.

