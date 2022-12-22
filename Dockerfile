# Creating build image. This image only installs the basic dependencies.
FROM klee/klee:2.3 as executable

RUN sudo add-apt-repository ppa:avsm/ppa && \
    sudo apt-get update && \
    sudo apt-get install --no-install-recommends -y \
                 m4 rsync pkg-config clang ocaml-nox opam python-matplotlib python-tk

# 3. Initializes the opam switch
RUN opam init --disable-sandboxing --disable-completion --shell=sh --shell-setup -y && \
    opam update

# Setup the working directory
ENV WORKDIR work
RUN mkdir -p $WORKDIR

# Install remaining dependencies
COPY --chown=klee klee4labels.opam $WORKDIR
RUN cd $WORKDIR && opam install . --deps-only -y

# Build the tool itself, and extend the PATH appropriately
COPY --chown=klee . $WORKDIR
RUN cd $WORKDIR && opam exec -- dune build @install
ENV PATH $PATH:/home/klee/$WORKDIR/_build/install/default/bin

# Hack the environment for clang to link properly against libkleeRuntest
ENV LIBRARY_PATH $LD_LIBRARY_PATH

# Define the entrypoint so `docker run -it` starts a bash prompt
ENTRYPOINT cd $WORKDIR && bash
