// let grammar, seq, choice, repeat, repeat1, optional, alias, field
//   prec = { left: 1, right: 1, dynamic: 1 }, token = {immediate: 1};

module.exports = grammar({
  name: 'Clojure',

  rules: {
    source_file: $=> repeat($.sExpression),

    sExpression: $=> seq('(', field('op', $.identifier), repeat($.expression), ')'),
    expression: $=> choice($.sExpression, $._collection, $.identifier, $._literal),

    _collection: $=> choice($.vector),
    vector: $=> seq('[', repeat($.expression), ']'),

    identifier: $=> /[:\-]?[a-zA-Z_][a-zA-Z0-9_?\-]*/,

    _literal: $=> choice($.stringLiteral),
    stringLiteral: $=> /"[^\r\n]*?"/

  }
});
