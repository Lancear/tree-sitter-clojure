// let grammar, seq, choice, repeat, repeat1, optional, alias, field
//   prec = { left: 1, right: 1, dynamic: 1 }, token = {immediate: 1};

module.exports = grammar({
  name: 'Clojure',

  extras: $=> [$._whitespace, $.comment],

  rules: {
    source_file: $=> repeat($.sExpression),

    sExpression: $=> seq('(', field('op', $.identifier), repeat($._expression), ')'),
    _expression: $=> choice($.sExpression, $._collection, $.identifier, $._literal),

    _collection: $=> choice($.vector),
    vector: $=> seq('[', repeat($._expression), ']'),

    identifier: $=> /[:\-]?[a-zA-Z_][a-zA-Z0-9_?\-]*/,

    _literal: $=> choice($.stringLiteral),
    stringLiteral: $=> /"[^\r\n]*?"/,

    _whitespace: $=> /\s+/,
    comment: $=> /;.*?\r?\n/
  }
});
