/*B*-drzewa to takie modyfikacje B-drzew, w których każda strona z wyjątkiem korzenia jest

zapełniona co najmniej w dwóch trzecich. Natomiast B+-drzewa to takie modyfikacje B-
drzewa, w których klucze są tylko w liściach (w węzłach wewnętrznych są jedynie wartości,

które pozwalają znaleźć klucz).
Dane jest B*+- drzewo rzędu m (połączenie B* i B+-drzewa). Napisz funkcję
convert_and_delete(v) która konwertuje B*+ drzewo rzędu m do B+-drzewa rzędu m a
następnie zaraz po konwersji usuwa zadany klucz v już w B+ drzewie.
Jaka jest praktyczna złożoność czasowa operacji wyszukiwania w B-drzewach i jak ją się
określa?*/
