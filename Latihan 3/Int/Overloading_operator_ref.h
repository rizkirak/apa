class X
{
 public:
  X& operator+=(const X& rhs) // compound assignment (does not need to be a member,
  {                           // but often is, to modify the private members)
    /* addition of rhs to *this takes place here */
    return *this; // return the result by reference
  }

  // friends defined inside class body are inline and are hidden from non-ADL lookup
  friend X operator+(X lhs,        // passing lhs by value helps optimize chained a+b+c
                     const X& rhs) // otherwise, both parameters may be const references
  {
    lhs += rhs; // reuse compound assignment
    return lhs; // return the result by value (uses move constructor)
  }
};
