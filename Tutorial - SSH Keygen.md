---
Aliases: 
---
> ID: 202205041012
> Tag: [[ssh]] [[42]]
> Type: #type/tutorial
> Status: #status/sown 
> Context: 
> PRVS: 
> NXT: 
> BRNCH: 

<!-- DRAFT NOTES
 
-->

# SSH Tutorial

- First, delete your public key (You don't need to, but let's start from the begining).

![[Peek 2022-05-04 10-20.gif]]

- Generate a new pair of SSH key, a public and a private key[^1] [^2]. Use the following command. Don't set a password in any step.

```bash
ssh-keygen -o -a 100 -t ed25519 -f ~/.ssh/42vogsphere -C "Your@email.com"
```

- Exibe your public key.

```bash
cat ~/.ssh/42vogsphere.pub
```

- Paste it in the intranet.

- Open the authentication agent to handle your new ssh-key[^3].

```bash
eval "$(ssh-agent -s)"
```

- Add your key.

```bash
ssh-add ~/.ssh/42vogsphere
```

- Now, use git normally.

```bash
git clone <your-repo-link> <folder-name>
cd <folder name>
touch teste.txt
git add .
git commit -m "<write a message>"
git push
```

### Extra - how to switch from PCs without recreate your key every time

- Save your keys into separate files and put the files in your pendrive.

```bash
cat ~/.ssh/42vogsphere > <file1>
cat ~/.ssh/42vogsphere.pub > <file2>
```

- Within another terminal, execute the opposite inclusion[^4].

```bash
cat <file1> > ~/.ssh/42vogsphere
cat <file2> > ~/.shh/42vogsphere
```

- Now, authenticate your key once again.

```bash
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/42vosphere
``` 

- That's it, just use your git workflow normally.

[^1]: To know more about the flags see the documentation [here](https://man7.org/linux/man-pages/man1/ssh-keygen.1.html).
[^2]: You can change 42vogsphere for another name if you want to; you can think that is a id like `~/.ssh/id_ed25519`.
[^3]: Learn more about it [here](https://man7.org/linux/man-pages/man1/ssh-agent.1.html).
[^4]: You'll overwrite the content of the ~/.ssh/42vogsphere file.