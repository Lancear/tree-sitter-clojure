#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 16
#define LARGE_STATE_COUNT 7
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 0
#define TOKEN_COUNT 7
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 4

enum {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  anon_sym_LBRACK = 3,
  anon_sym_RBRACK = 4,
  sym_identifier = 5,
  sym_stringLiteral = 6,
  sym_source_file = 7,
  sym_sExpression = 8,
  sym_expression = 9,
  sym__collection = 10,
  sym_vector = 11,
  sym__literal = 12,
  aux_sym_source_file_repeat1 = 13,
  aux_sym_sExpression_repeat1 = 14,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_identifier] = "identifier",
  [sym_stringLiteral] = "stringLiteral",
  [sym_source_file] = "source_file",
  [sym_sExpression] = "sExpression",
  [sym_expression] = "expression",
  [sym__collection] = "_collection",
  [sym_vector] = "vector",
  [sym__literal] = "_literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_sExpression_repeat1] = "sExpression_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_identifier] = sym_identifier,
  [sym_stringLiteral] = sym_stringLiteral,
  [sym_source_file] = sym_source_file,
  [sym_sExpression] = sym_sExpression,
  [sym_expression] = sym_expression,
  [sym__collection] = sym__collection,
  [sym_vector] = sym_vector,
  [sym__literal] = sym__literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_sExpression_repeat1] = aux_sym_sExpression_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_stringLiteral] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_sExpression] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__collection] = {
    .visible = false,
    .named = true,
  },
  [sym_vector] = {
    .visible = true,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_sExpression_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_op = 1,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_op] = "op",
};

static const TSFieldMapSlice ts_field_map_slices[2] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_op, 1},
};

static TSSymbol ts_alias_sequences[2][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(3);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '(') ADVANCE(4);
      if (lookahead == ')') ADVANCE(5);
      if (lookahead == '[') ADVANCE(6);
      if (lookahead == ']') ADVANCE(7);
      if (lookahead == '-' ||
          lookahead == ':') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(1);
      END_STATE();
    case 2:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_stringLiteral);
      if (lookahead == '"') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(1);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_stringLiteral] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(15),
    [sym_sExpression] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
  [2] = {
    [sym_sExpression] = STATE(9),
    [sym_expression] = STATE(2),
    [sym__collection] = STATE(9),
    [sym_vector] = STATE(9),
    [sym__literal] = STATE(9),
    [aux_sym_sExpression_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(10),
    [anon_sym_LBRACK] = ACTIONS(12),
    [anon_sym_RBRACK] = ACTIONS(10),
    [sym_identifier] = ACTIONS(15),
    [sym_stringLiteral] = ACTIONS(15),
  },
  [3] = {
    [sym_sExpression] = STATE(9),
    [sym_expression] = STATE(5),
    [sym__collection] = STATE(9),
    [sym_vector] = STATE(9),
    [sym__literal] = STATE(9),
    [aux_sym_sExpression_repeat1] = STATE(5),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_RPAREN] = ACTIONS(18),
    [anon_sym_LBRACK] = ACTIONS(20),
    [sym_identifier] = ACTIONS(22),
    [sym_stringLiteral] = ACTIONS(22),
  },
  [4] = {
    [sym_sExpression] = STATE(9),
    [sym_expression] = STATE(6),
    [sym__collection] = STATE(9),
    [sym_vector] = STATE(9),
    [sym__literal] = STATE(9),
    [aux_sym_sExpression_repeat1] = STATE(6),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACK] = ACTIONS(20),
    [anon_sym_RBRACK] = ACTIONS(24),
    [sym_identifier] = ACTIONS(22),
    [sym_stringLiteral] = ACTIONS(22),
  },
  [5] = {
    [sym_sExpression] = STATE(9),
    [sym_expression] = STATE(2),
    [sym__collection] = STATE(9),
    [sym_vector] = STATE(9),
    [sym__literal] = STATE(9),
    [aux_sym_sExpression_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_RPAREN] = ACTIONS(26),
    [anon_sym_LBRACK] = ACTIONS(20),
    [sym_identifier] = ACTIONS(22),
    [sym_stringLiteral] = ACTIONS(22),
  },
  [6] = {
    [sym_sExpression] = STATE(9),
    [sym_expression] = STATE(2),
    [sym__collection] = STATE(9),
    [sym_vector] = STATE(9),
    [sym__literal] = STATE(9),
    [aux_sym_sExpression_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACK] = ACTIONS(20),
    [anon_sym_RBRACK] = ACTIONS(28),
    [sym_identifier] = ACTIONS(22),
    [sym_stringLiteral] = ACTIONS(22),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(30), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_identifier,
      sym_stringLiteral,
  [10] = 1,
    ACTIONS(32), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_identifier,
      sym_stringLiteral,
  [20] = 1,
    ACTIONS(34), 6,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_identifier,
      sym_stringLiteral,
  [29] = 1,
    ACTIONS(36), 6,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_identifier,
      sym_stringLiteral,
  [38] = 1,
    ACTIONS(38), 6,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      sym_identifier,
      sym_stringLiteral,
  [47] = 3,
    ACTIONS(5), 1,
      anon_sym_LPAREN,
    ACTIONS(40), 1,
      ts_builtin_sym_end,
    STATE(13), 2,
      sym_sExpression,
      aux_sym_source_file_repeat1,
  [58] = 3,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    ACTIONS(44), 1,
      anon_sym_LPAREN,
    STATE(13), 2,
      sym_sExpression,
      aux_sym_source_file_repeat1,
  [69] = 1,
    ACTIONS(47), 1,
      sym_identifier,
  [73] = 1,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(7)] = 0,
  [SMALL_STATE(8)] = 10,
  [SMALL_STATE(9)] = 20,
  [SMALL_STATE(10)] = 29,
  [SMALL_STATE(11)] = 38,
  [SMALL_STATE(12)] = 47,
  [SMALL_STATE(13)] = 58,
  [SMALL_STATE(14)] = 69,
  [SMALL_STATE(15)] = 73,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [7] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sExpression_repeat1, 2), SHIFT_REPEAT(14),
  [10] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_sExpression_repeat1, 2),
  [12] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sExpression_repeat1, 2), SHIFT_REPEAT(4),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_sExpression_repeat1, 2), SHIFT_REPEAT(9),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sExpression, 3, .production_id = 1),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sExpression, 4, .production_id = 1),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 2),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_vector, 3),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [49] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_Clojure(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const uint16_t *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .field_count = FIELD_COUNT,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .field_names = ts_field_names,
    .large_state_count = LARGE_STATE_COUNT,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .state_count = STATE_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
