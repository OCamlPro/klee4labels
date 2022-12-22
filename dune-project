(lang dune 3.4)

(name klee4labels)

(generate_opam_files true)

(source
 (github OCamlPro/klee4labels))

(authors "Steven de Oliveira <steven.de-oliveira@ocamlpro.com>"
	 "Nicolas Berthier <nicolas.berthier@ocamlpro.com>"
	 "Nikolai Kosmatov <nikolai.kosmatov@thalesgroup.com>"
	 "Delphine Longuet <delphine.longuet@thalesgroup.com>"
	 "Romain Soulat <romain.soulat@thalesgroup.com>")
(maintainers "Steven de Oliveira <steven.de-oliveira@ocamlpro.com>"
	     "Nicolas Berthier <nicolas.berthier@ocamlpro.com>")

(license "GPL-3.0-or-later")

; (documentation https://url/to/documentation)

(package
 (name klee4labels)
 (synopsis "Klee for labels")
 (description "Klee for labels")
 (depends
	ocaml
	dune
	lwt
	ocamlgraph
	json-data-encoding
	inotify
	ppx_deriving_encoding
	yojson
 )
 (tags
  (topics "test generation; dynamic symbolic execution; klee" your project)))

; See the complete stanza docs at https://dune.readthedocs.io/en/stable/dune-files.html#dune-project
