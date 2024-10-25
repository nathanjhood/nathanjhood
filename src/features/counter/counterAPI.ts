declare namespace fetchCount {}

interface fetchCount {
  (amount?: number): Promise<{ data: number }>
}

// A mock function to mimic making an async request for data
const fetchCount: fetchCount = (amount = 1) => {
  return new Promise<{ data: number }>(resolve =>
    setTimeout(() => resolve({ data: amount }), 500),
  )
}

export = fetchCount;
