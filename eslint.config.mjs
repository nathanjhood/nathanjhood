/**
 * @file eslint.config.mjs
 * @author Nathan J. Hood <nathanjhood@googlemail.com>
 * @brief
 * @version 0.1.0
 * @date 2024-09-05
 *
 * @copyright Copyright (c) 2024
 *
 */

import pluginJs from '@eslint/js';
import eslintConfigPrettier from 'eslint-config-prettier';
import globals from 'globals';
import tseslint from 'typescript-eslint';
//@ts-check

/** @type {import('typescript-eslint').Config} */
const configs = [
  {files: ['*.{c,m,}{t,j}s', '*.{t,j}sx']},
  {files: ['*{test,spec}.{t,j}s?(x)'], env: {jest: true}},
  {files: ['**/*.js'], languageOptions: {sourceType: 'script'}},
  {languageOptions: {globals: globals.browser}},
  pluginJs.configs.recommended,
  ...tseslint.configs.recommended,
  {
    rules: {
      '@typescript-eslint/no-explicit-any': 'off',
      '@typescript-eslint/no-unused-vars': 'warn',
      '@typescript-eslint/no-require-imports': 'off',
      '@typescript-eslint/no-empty-object-type': 'off',
      // from redux cra template
      '@typescript-eslint/consistent-type-imports': [
        2,
        {fixStyle: 'separate-type-imports'},
      ],
      '@typescript-eslint/no-restricted-imports': [
        2,
        {
          paths: [
            {
              name: 'react-redux',
              importNames: ['useSelector', 'useStore', 'useDispatch'],
              message:
                'Please use pre-typed versions from `app/hooks.ts` instead.',
            },
          ],
        },
      ],
    },
  },

  eslintConfigPrettier, // Make sure to put it last, so it gets the chance to override other configs.
];

export default configs;
