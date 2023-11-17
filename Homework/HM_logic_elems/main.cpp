enum Elem_types {
    Source,
    Or,
    And
}

class Logic_elements {
public:
    Elem_types type;
    bool inverted;
    bool sygnal;
private:

    Logic_elements(Elem_types tp, bool inv) : type{tp}, inverted{inv}, sygnal{0} {}

}