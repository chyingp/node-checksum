{
  "targets": [
    {
      "target_name": "checksum",
      "sources": [ "checksum.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}