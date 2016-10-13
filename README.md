# configmagic
A really tiny programm to replace config variables in files

# Usage

```bash
CM_something=anything ./configmagic <inputfile> <outputfile>
```

`configmagic` uses environment variables following the schema `CM_something` and replaces all `%something%` in inputfile with the value of the environment variable.

## Where to use it?

`configmagic` is built for usage in dockercontainer where you don't want to use big config management or templating engines like [Puppet](https://puppet.com/) oder [Ansible](http://ansible.com).

# Build
```bash
g++ configmagic.cpp -o configmagic
```

# Hint
`configmagic` is a quick and dirty solution for a simple problem. Feel free to improve by adding a pull request :wink:
