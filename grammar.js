// let grammar, seq, choice, repeat, repeat1, optional, alias, field
//   prec = { left: 1, right: 1, dynamic: 1 }, token = {immediate: 1};

module.exports = grammar({
  name: 'Clojure',

  extras: $=> [$._whitespace, $.comment],
  supertypes: $=> [
    $._expression, 
    $._collection, 
    $._literal, 
    $._numericLiteral
  ],

  rules: {
    source_file: $=> repeat($.sExpression),

    sExpression: $=> seq('(', field('op', $.identifier), field('operands', repeat($._expression)), ')'),
    _expression: $=> choice($.sExpression, $._collection, $.identifier, $._literal),

    _collection: $=> choice($.vector),
    vector: $=> seq('[', repeat($._expression), ']'),

    identifier: $=> /[:\-]?[a-zA-Z_][a-zA-Z0-9_?\-]*/,

    _literal: $=> choice($.stringLiteral, $._numericLiteral),

    _numericLiteral: $=> choice($.integer, $.floatingPoint, $.ratio),
    integer: $=> /[+\-]?(0[0-7]+|0x[a-fA-F0-9]+|\d\d?r[a-zA-Z0-9]+|\d+)N?/, // todo: check radix nums
    floatingPoint: $=> /([+\-]?\d+(\.\d*)?(e[+\-]?\d+)M?)|##Inf|##-Inf|##NaN/,
    ratio: $=> /\d+\/\d+/,

    stringLiteral: $=> /"[^\r\n]*?"/,

    _whitespace: $=> /\s+/,
    comment: $=> /;.*?\r?\n/
  }
});
