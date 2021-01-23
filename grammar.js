// let grammar, seq, choice, repeat, repeat1, optional, alias, field
//   prec = { left: 1, right: 1, dynamic: 1 }, token = {immediate: 1};

module.exports = grammar({
  name: 'Clojure',

  extras: $=> [$._whitespace, $.comment],
  supertypes: $=> [
    $._expression, 
    $._collection, 
    $._literal, 
    $._numericLiteral,
    $._characterLiteral
  ],

  rules: {
    source_file: $=> repeat($.sExpression),

    // -- Expressions --- //
    sExpression: $=> seq('(', field('op', $.identifier), field('operands', repeat($._expression)), ')'),
    _expression: $=> choice($.sExpression, $._collection, $.identifier, $._literal),

    // -- Collections --- //
    _collection: $=> choice($.list, $.vector, $.set, $.map),
    list: $=> seq('\'(', repeat($._expression), ')'),
    vector: $=> seq('[', repeat($._expression), ']'),
    set: $=> seq('#{', repeat($._expression), '}'),
    map: $=> seq('{', repeat($.mapEntry), '}'),

    mapEntry: $=> seq($._expression, $._expression),

    // -- Symbols --- //
    identifier: $=> /[:\-]?[a-zA-Z_][a-zA-Z0-9_?\-]*/,


    // --- Literals --- //
    _literal: $=> choice($._numericLiteral, $._characterLiteral),

    _numericLiteral: $=> choice($.integer, $.floatingPoint, $.ratio),
    integer: $=> /[+\-]?(0[0-7]+|0x[a-fA-F0-9]+|\d+)N?|\d\d?r[a-zA-Z0-9]+/,
    floatingPoint: $=> /[+\-]?\d+(\.\d*)?(e[+\-]?\d+)M?|##Inf|##-Inf|##NaN/,
    ratio: $=> /\d+\/\d+/,

    _characterLiteral: $=> choice($.string, $.character, $.regex),
    string: $=> /"[^\r\n]*?"/,
    character: $=> /\\[^\s]|\\u\d{4}|\\o\d{3}|\\newline|\\return|\\space|\\tab/,
    regex: $=> /#"[^\r\n]*?"/,

    // --- Extras --- //
    _whitespace: $=> /[\s,]+/,
    comment: $=> /;.*?\r?\n/,
  }
});
